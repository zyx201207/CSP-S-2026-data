#include<bits/stdc++.h>
using namespace std;
long long crystal[1000086];
int main(){
	freopen("crystal.in","r",stdin); 
	freopen("crystal.out","w",stdout);
	long long n,m,cnt,flag=1,maxn=1; 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>crystal[i];
	}
	sort(crystal+1,crystal+n+1);
	for(int i=1;i<=n;i++){
		if(i==2){
			cnt=crystal[i]-crystal[i-1];
		}
		else if(i!=1){
			if(crystal[i]-crystal[i-1]!=cnt){
				flag=0;
			}
		}
	}
	if(flag==1){
		long long now=m,i=0,num=n;
		while(now>=0&&num>0){
			i++;
			now-=i*cnt;
			num--;
		}
		cout<<i;
	}
	else{
		for(int now=1;now<=n;now++){
			long long change=m,ans=1;
			for(int i=now-1;i>=1;i--){
				if(crystal[now]-crystal[i]<=m){
//					cout<<"!!!!!!!!!!!!!!!Ñ¡Ôñ£º"<<crystal[i]<<endl;
					m-=crystal[now]-crystal[i];
//					cout<<"!!!!!!!!!!!!!!!!!m:"<<m<<endl;
					ans++;
				}
				else{
					break;
				}
			}
//			cout<<"__________________________"<<endl;
			maxn=max(maxn,ans);
			m=change;
		}
		cout<<maxn;
	}
}
