#include<bits/stdc++.h>
using namespace std;
#define itn int
#define endl "\n"
#define ll long long
ll n,a[200005],pos,ans,id,sum,cnt;
char s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
		pos+=a[i];
	}ans=pos;
	pos=pos+bool(pos%2)>>1;
	for(int i=1;i<=n;i++){
		sum+=a[i];
		if(sum>pos){
			id=i;
			break;
		}
	}if(ans&1){
		for(int i=1,j=n;i<=id;i++,j--){
			if(i==j)break;
			if(s[i]!=s[j])cnt+=min(a[i],a[j]);
			if(a[i]<a[j]){
				ll cha=a[j]-a[i];
				int jj;
				for(jj=i+1;jj<=id;jj++){
					if(s[jj]!=s[j]){
						cnt+=min(cha,a[jj]);
					}if(a[jj]>cha){
						a[jj]-=cha;
						break;
					}cha-=a[jj];
					a[jj]=0;
				}i=jj-1;
			}else if(a[i]>a[j]){
				ll cha=a[i]-a[j];
				int jj;
				for(jj=j-1;jj>=id;jj--){
					if(s[jj]!=s[i]){
						cnt+=min(cha,a[jj]);
					}if(a[jj]>cha){
						a[jj]-=cha;
						break;
					}cha-=a[jj];
					a[jj]=0;
				}j=jj+1;
			}
		}cout<<cnt;
		return 0;
	}else{
		for(int i=1,j=n;i<id;i++,j--){
			if(i==j)break;
			if(s[i]!=s[j])cnt+=min(a[i],a[j]);
			if(a[i]<a[j]){
				ll cha=a[j]-a[i];
				int jj;
				for(jj=i+1;jj<id;jj++){
					if(s[jj]!=s[j]){
						cnt+=min(cha,a[jj]);
					}if(a[jj]>cha){
						a[jj]-=cha;
						break;
					}cha-=a[jj];
					a[jj]=0;
				}i=jj-1;
			}else if(a[i]>a[j]){
				ll cha=a[i]-a[j];
				int jj;
				for(jj=j-1;jj>id;jj--){
					if(s[jj]!=s[i]){
						cnt+=min(cha,a[jj]);
					}if(a[jj]>cha){
						a[jj]-=cha;
						break;
					}cha-=a[jj];
					a[jj]=0;
				}j=jj+1;
			}
		}cout<<cnt;
		return 0;
	}return 0;
}
