
public class MaxOps {
    
    /* Written by Philip Hobby. 
     * Recursive Approach */

    public static void main(String[] args) {
        int[] nums = {10, 5, 5, 5, 5, 5, 5, 5, 5, 0, 15, 0}; //expected answer is 5
                                                              //(5 10s; 15 gets you 2; 15 gets you only 2)
        
        /* Note that this program fails if nums.length < 2 (as the next six lines of code are subtracting at times up to 2
           However, please note that in the parameters of the assignment, 2 <= nums.length <= 2000. */
        
        // There are only 3 possible sums this could come out to: the sum of the two ends, the sum of the first two, or the sum of the last two.
        int endsSum = nums[0] + nums[nums.length - 1];
        int firstsSum = nums[0] + nums[1];
        int lastsSum = nums[nums.length - 1] + nums[nums.length - 2];
        
        // The following have a 1 added to them, because doing this calculation automatically is 1 operation
        int numberOfEndsOperations = calculateNumberOfOperations(endsSum, removeEnds(nums)) + 1;
        int numberOfFirstsOperations = calculateNumberOfOperations(firstsSum, removeFirsts(nums)) + 1;
        int numberOfLastsOperations = calculateNumberOfOperations(lastsSum, removeLasts(nums)) + 1;
        
        // Prints out the largest of the three counters of operations.
        System.out.print(biggestOf(numberOfEndsOperations, numberOfFirstsOperations, numberOfLastsOperations));

    }


    private static int[] removeEnds(int[] array) {
        if (array.length >= 2) {
            int[] newArray = new int[array.length - 2];
            
            for (int i = 0; i <= array.length - 3; i++) { //skip the first and skip the last
                newArray[i] = array[i+1];
            }
            
            return newArray;
            
        }
        else {  //if it's length = 1, it should just return the array; if it's empty, it should also return the same array.
            return array;
        }
    }
    
    private static int[] removeLasts(int[] array) {
        if (array.length >= 2) {
            int[] newArray = new int[array.length - 2];
            
            for (int i = 0; i <= array.length - 3; i++) { //skip the first and skip the last
                newArray[i] = array[i]; //this deletes the last two by virtue of the fact that it never gets to them.
            }
            
            return newArray;
            
        }
        else {  //if it's length = 1, it should just return the array; if it's empty, it should also return the same array.
            return array;
        }
    }

    private static int[] removeFirsts(int[] array) {
        if (array.length >= 2) {
            int[] newArray = new int[array.length - 2];
            
            for (int i = 0; i <= array.length - 3; i++) { //skip the first and skip the last
                newArray[i] = array[i+2]; //this skips over the first two of the array.
            }
            
            return newArray;
            
        }
        else {  //if it's length = 1, it should just return the array; if it's empty, it should also return the same array.
            return array;
        }
    }


    private static int calculateNumberOfOperations(int targetSum, int[] array) {
        
        if (array.length < 2) { //i.e. no more operations possible
            return 0;
        }
        else { // return the largest of all three options
            int ends = 0;
            int firsts = 0;
            int lasts = 0;
            
            if (targetSum == array[0] + array[array.length - 1]) {
                ends = 1 + calculateNumberOfOperations(targetSum, removeEnds(array));
            }
            if (targetSum == array[0] + array[1]) { // testing if firsts
                firsts = 1 + calculateNumberOfOperations(targetSum, removeFirsts(array));
            }
            if (targetSum == array[array.length - 1] + array[array.length - 2]) { //testing if lasts 
                lasts = 1 + calculateNumberOfOperations(targetSum, removeLasts(array));
            }
            
            return biggestOf(ends, firsts, lasts);
        }
    }


    private static int biggestOf(int ends, int firsts, int lasts) {
        int biggest = 0;
        if (ends > biggest) {
            biggest = ends;
        }
        if (firsts > biggest) {
            biggest = firsts;
        }
        if (lasts > biggest) {
            biggest = lasts;
        }
        return biggest;

    }
}
