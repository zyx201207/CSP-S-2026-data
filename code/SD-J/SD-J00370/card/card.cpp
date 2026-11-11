#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int n,m,a[500010],q[500050],h,t,last[500050],cnt[500050];
int a1[500010],a2[500010],b1,b2;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	    cin>>a[i];
	if(m==1){
		cout<<n;
	}else if(m==2&&n>=200000){
		b1=a[1];
		for(int i=2;i<=n;i++){
			if(a[i]!=b1){
				b2=a[i];
				i=n+1;
			}
		}
		for(int i=1;i<=n;i++){
			a1[i]=a1[i-1]+(a[i]==b1);
			a2[i]=a2[i-1]+(a[i]==b2);
		}
		for(int i=1;i<=n;i++){
			if((a1[n]-a1[i])%2==1)
			    cnt[1]++;
			if((a2[n]-a2[i])%2==1)
			    cnt[2]++;
		}
		cout<<cnt[1]<<' '<<cnt[2];
	}else{
		for(int i=1;i<=n;i++){//第i局游戏 
			h=t=1;
			memset(last,0,sizeof last);
			for(int j=i;j<=n;j++){//第j张卡片 
				if(last[a[j]]>=1&&last[a[j]]<=t-1){
					t=last[a[j]]+1;
				}else{
					q[t]=a[j];
					last[a[j]]=t;
					t++;
				}
			}//由于只要出现相同的卡片就会消除，不需要考虑重复加算情况
			while(h<=t-1){
				cnt[q[h]]++;
				h++;
			}
		}
		for(int i=1;i<=m;i++)
		    cout<<cnt[i]<<' ';
	}
	return 0;
} 
