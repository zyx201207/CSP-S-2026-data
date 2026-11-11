#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1;
string str="";
char cha[N];
int num;
long long ans=0,len[N],lenr=0;
long long lft,rht;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>num;
	for(int i=1;i<=num;++i){//输入 
		scanf("%lld",&len[i]);
		cin>>cha[i];
		lenr+=len[i];
	}
	long long lft=1,rht=lenr,i=1,j=num;
	while(i<=j){
		if(cha[i]!=cha[j]){//寻找不同子串 
			ans+=min(len[i],len[j]);//累加长度较短子串 
		}
		if(len[i]<len[j]){//改变指针的值 
			len[j]-=len[i];
			++i;
		}
		else{
			len[i]-=len[j];
			--j;
		}
		lft+=min(len[i],len[j]);
		rht-=min(len[i],len[j]);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

