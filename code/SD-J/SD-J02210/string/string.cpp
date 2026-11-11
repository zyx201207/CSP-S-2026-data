#include<bits/stdc++.h>
using namespace std;
long long cnt=0,sum=0;
int n;
string s;
bool flag=0,f=0;
struct node{
	int num;
	char c;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].c;
		if(i>1&&a[i].c!=a[i-1].c) flag=1;
		if(a[i].num>500) f=1;
		sum+=a[i].num;
	}
	if(flag==0){
		printf("%d",0);
		return 0;
	}
	if(!f){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=a[i].num;j++) s=s+a[i].c;
		}
		long long l=0,r=s.size()-1;
		while(l<=r){
			if(s[l]!=s[r]) cnt++;
			l++,r--;
		}
		printf("%lld",cnt);
	}else printf("%d",sum/2);
	return 0;
} 
