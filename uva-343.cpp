#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;

//字符数值
int ValueChar(char ch)
{
	if(ch>='0'&&ch<='9')
		return ch-'0';//数字则返回数字的值
	return ch-'A'+10;//A-Z
}

//字符串数值
int ValueStr(int base, char buf[])
{
	int value=0;
	for(int i=0;i<strlen(buf);i++)
	{
		value*=base;
		value+=ValueChar(buf[i]);
	}
	return value;
}

main()
{
	char str1[101],str2[101];
	while(cin>>str1>>str2)
	{
		//找最小进制
		int max1=1,max2=1;
		for(int i=0;i<strlen(str1);i++)
			if(max1<ValueChar(str1[i]))
				max1=ValueChar(str1[i]);
		for(int i=0;i<strlen(str2);i++)
			if (max2<ValueChar(str2[i]))
				max2=ValueChar(str2[i]);
		//查找不同的进制时相同的值
		int flag=0;
		for(int i=max1+1;i<37;i++)
		{
			for(int j=max2+1;j<37;j++)
				if(!flag&&ValueStr(i,str1)==ValueStr(j,str2))
				{
					flag=1;
					printf("%s (base %d) = %s (base %d)\n",str1,i,str2,j);
				}
		}
		if(!flag)
			printf("%s is not equal to %s in any base 2..36\n",str1,str2);
	}
}
