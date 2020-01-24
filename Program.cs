using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp2
{
    public class Program
    {
        public static void Main(string[] args)
        {

            int[] num = new int[10];
            for (int i = 0; i < 9; i++)
                num[i] = (i + 1);
            num[9] = 0;

            /*for(int i=0;i<10;i++)
                Console.WriteLine(num[i]+ "\n");*/

            Console.WriteLine("Output :" + CreatePhoneNumber(num));
        }


        public static string CreatePhoneNumber(int[] numbers)
        {
            string strNum = "(";

            for (int i = 0; i < numbers.Length; i++)
                strNum += numbers[i];
            
            strNum = strNum.Insert(4, ")");
            strNum = strNum.Insert(5, " ");
            strNum = strNum.Insert(9, "-");

            return strNum;
        }

    }
}
