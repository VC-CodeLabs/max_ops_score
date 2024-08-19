use std::cmp;

fn calc_score(nums: &[i32], target_score: i32) -> i32 {
    let len = nums.len();
    if len < 2 {
        return 0;
    }

    // calc total of the first 2 elements in the list
    let mut tot = nums[0] + nums[1];
    let mut result = 0;

    if target_score == 0 || tot == target_score {
        // if match, send a slice using the remaining elements to calc_score to determine 
        // how many other combos match this total
        result = 1 + calc_score(&nums[2..len], tot);
    }
    else {
        // Try the last 2 elements in the array
        tot = nums[len-2] + nums[len-1];
        if tot == target_score {
            // if match, send a slice using the remaining elements to calc_score to determine 
            // how many other combos match this total
            result = 1 + calc_score(&nums[0..len-2], target_score);
        }
        else {
            // try the first & last elements
            tot = nums[0] + nums[len-1];
            if tot == target_score {
                // if match, send a slice using the remaining elements to calc_score to determine 
                // how many other combos match this total
                result = 1 + calc_score(&nums[1..len-1], target_score)
            }
        }
    }
    return result
    
}

fn find_max_score(nums: &[i32]) -> i32 {
    let result1 = calc_score(&nums, 0);

    let result2 = calc_score(&nums[0..nums.len()-2], nums[nums.len()-2] + nums[nums.len()-1]);
    let result3 = calc_score(&nums[1..nums.len()-1], nums[0] + nums[nums.len()-1]);

    let mut max = cmp::max(result1,result2);
    max = cmp::max(max,result3);
    return max;
}

fn main() {
    // Candidate numbers to score
    let nums = vec![7,1,8,6,2,12,13,7];

    let max = find_max_score(&nums);

    println!("{}", max);
}


// BLAH! Couldn't figure out the stupid borrowing for multiple threads.
//
// fn find_max_score_conc(nums: &[i32]) -> i32 {
//     let (tx1, rx1) = mpsc::channel();
//     let (tx2, rx2) = mpsc::channel();
//     let (tx3, rx3) = mpsc::channel();

//     let nums1 = Arc::clone(nums);
//     let nums2 = Arc::clone(nums);
//     let nums3 = Arc::clone(nums);

//     thread::spawn(move || {
//         let result1 = calc_score(&nums1, 0);
//         tx1.send(result1).unwrap();
//     });

//     thread::spawn(move || {
//         let result2 = calc_score(&nums2[0..nums2.len()-2],  nums2[nums2.len()-2] + nums2[nums2.len()-1]);
//         tx2.send(result2).unwrap();
//     });

//     thread::spawn(move || {
//         let result3 = calc_score(&nums3[1..nums3.len()-1], nums3[0] + nums3[nums3.len()-1]);
//         tx3.send(result3).unwrap();
//     });
//     let result1 = rx1.recv().unwrap();
//     let result2 = rx2.recv().unwrap();
//     let result3 = rx3.recv().unwrap();

//     let mut max = cmp::max(result1,result2);
//     max = cmp::max(max,result3);
//     return max;
// }

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test1() {
        let nums = vec![3,2,1,2,3,4];
        let result = find_max_score(&nums);
        assert_eq!(3, result);
    }

    #[test]
    fn test2() {
        let nums = vec![3,2,6,1,4];
        let result = find_max_score(&nums);
        assert_eq!(2, result);
    }

    #[test]
    fn test3() {
        // 11 -> 10+1, 4+7, 6+5
        // 17 -> 1
        // 12 -> 1 
        let nums = vec![10,1,4,6,2,3,5,7];
        let result = find_max_score(&nums);
        assert_eq!(3, result);
    }

    #[test]
    fn test4() {
        // [0]+[7] = 14 -> 3
        // [0]+[1] = 8 -> 1
        // [6]+[7] = 20 -> 1 
        let nums = vec![7,1,8,6,2,12,13,7];
        let result = find_max_score(&nums);
        assert_eq!(3, result);
    }
}

