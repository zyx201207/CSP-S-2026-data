#include<bits/stdc++.h>
using namespace std;
char s[10000000000000];
long long cnt=0;
long long sum=0;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;

	
	for(int i=0;i<n;i++){
		long long a;		
		char b;
		cin>>a>>b;
		for(int j=sum;j<a+sum;j++){
			s[j]=b;//读取 
			cnt++;//判断有几位		
		}
		sum=cnt;
	}//读取数组 
	int t=0;
	for(int i=1;i<cnt;i++){
		if(s[i]!=s[i-1]){
			t++;
		}
	}
	if(t==0){
	   cout<<0;
	   return 0; 
	}//判断是否整个数组为一个字符 
	int q=0;
   for(int i=0;i<cnt;i++){//i++和cnt--前后照应有没有一致 
   	if(cnt==i||cnt<i){
   		 break;
	   }//遍历是否过半 
	  
   	   if(s[i]!=s[cnt]){
   	   	q++;//不一致改一次，次数加一 
		}//前后是否一致 
		cnt--;
   }
   cout<<q;
	return 0;
}
