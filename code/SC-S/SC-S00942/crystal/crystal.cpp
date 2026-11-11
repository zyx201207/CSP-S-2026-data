#include<bits/stdc++.h>

using namespace std;
long long a[500010];
int n;long long m;
int main()
{
	freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
	int n;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);long long ans=0;long long amin=a[1];long long amax=a[n];
	if(n<=5000){
		for(int i=1;i<=n;i++){
			long long base=a[i];long long tmp=m;long long ans1=1;
			for(int j=i-1;j>=1;j--){
				long long cha=base-a[j];
				if(tmp>=cha){
					tmp-=cha;
					ans1++;
				}else{
					break;
				}
			}
			ans=max(ans1,ans);
		}
		cout<<ans;
	}else{
		bool flag1=0;long long x=a[1];
		for(int i=2;i<=n;i++){
			if(a[i]!=x){
				flag1=1;break;
			}
		}
		if(flag1==0){
			cout<<n<<endl;return 0;
		}else if(amax-amin<=300){
			long long ans=0;long long last=n;
			for(long long i=amax;i>=amin;i--){
				int p=0;long long tmp=m;
				for(int j=last;j>=1;j--){
					if(a[j]==i){
						p=j;break;
					}
				}
				if(p==0){
					continue;
				}else{
					last=p;
					long long ans1=1;long long base=a[p];
					for(int j=p-1;j>=1;j--){
						long long cha=base-a[j];
						if(tmp>=cha){
							tmp-=cha;ans1++;
						}else{
							break;
						}
					}
					ans=max(ans,ans1);
				}
				
			}
			cout<<ans<<endl;
		}else{
			long long v=a[2]-a[1];
			long long res=0;long long tmp=0;
			for(long long  i=n;i>=1;i--){
				tmp=(i*(i-1))*v/2;
				if(tmp<=m){
					res=i;break;
				}
			}
			cout<<res;
		}
	}
	return 0;
 } 