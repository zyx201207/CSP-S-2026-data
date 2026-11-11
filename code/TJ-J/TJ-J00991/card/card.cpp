#include<bits/stdc++.h>
using namespace std;
long long c,x,n,m,t[1000005],a[1000005],ans,ma,f,f1=1,f1_,f2,st[1000005],cnt[1000005],cnt1[1000005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	if(n==1){
		cout<<1;
		return 0;
	}
	if(n==2){
		cout<<2<<' '<<1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		c=0;
		for(int j=1;j<=n;j++){
			st[j]=0;
		}
		for(int j=1;j<=m;j++){
			t[j]=0;
		}
		for(int j=1;j<=n-i+1;j++){
			
			cin>>st[j-c];
			if(t[st[j-c]]!=1){
				t[st[j-c]]=1;
			}
			else{
				int f=0;
				for(int k=1;k<=n;k++){
					if(st[k]==st[j]&&f==1){
						f=0;
						c++;
						
						break;
					}
					if(f){
						st[k]=0;
						c++;
					}
					if(st[k]==st[j]&&f==0){
						f=1;
					}
					
				}
				t[st[j]]=0;
				st[j]=0;
			}
		}
		f=0;
		for(int j=1;j<=m;j++){
			for(int k=1;k<=n;k++){
				if(j==st[k]){
					f=1;
					break;
				}
			}
			if(f){
				cnt[j]++;
			}
		}
		
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<' ';
	}
	return 0;
}
