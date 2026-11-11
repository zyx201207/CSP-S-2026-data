#include<bits/stdc++.h>
using namespace std;
int n,m,daan=-999999999;
int a[10000000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<pow(n,m);i++){
		int num=i,ji=0;
		string s;
		while(num){
			s+=num%2+'0';
			if(num%2==1) ji++;
			num=num>>1;
		}
		if(ji!=m) continue;
		int ans=0,flag=1;
		for(int i=0;i<=s.size();i++){
			if(s[i]=='1'){
				if(flag){
					ans+=a[i];
					flag=0;
				}else ans=ans&a[i];
				 
			}
		}daan=max(daan,ans);
	}cout<<daan;
	return 0;
}
