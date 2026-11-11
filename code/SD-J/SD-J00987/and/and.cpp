#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],cnt[5],maxx=-1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(a[i],maxx);
	}
	if(maxx==3){
		for(int i=1;i<=n;i++){
			cnt[a[i]]++;
		}
		if(cnt[3]>=m){
			cout<<3;
		}
		else if(cnt[3]+cnt[2]>m){
			cout<<2;
		}
		else if(cnt[3]+cnt[1]>m){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else if(m==1){
		cout<<maxx;
	}
	else if(m==2){
		int maxa=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxa=max(maxa,int(a[i]&a[j]));
			}
		}
		cout<<maxa;
	}
	else if(n<=20){
		int maxf=-1;
		for(int s=1;s<=(1<<n);s++){
			int ss=s,check=0,flag=0,anss=0,i=0;
			while(ss>0){
				check+=(ss&1);
				ss>>=1;
			}
			if(check==m){
				int sss=s;
				while(sss>0){
					i++;
					if(sss&1){
						if(!flag){
							anss=a[i];
						}
						else{
							anss=(anss&a[i]);
						}
					}
					sss>>=1;
				}
			}
			maxf=max(maxf,anss);
		}
		cout<<maxf;
	}
}
