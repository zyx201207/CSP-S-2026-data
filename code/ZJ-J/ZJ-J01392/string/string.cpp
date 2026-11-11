#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int n;
struct ovo{
	char z;
	int op;
}a[N];
int ans=0;
int zifuchuan=0;
int pre[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].op>>a[i].z;
		zifuchuan+=a[i].op;
		pre[i]=pre[i-1]+a[i].op;
	}
	string s1,s2;
	int sum=0;
	int mark;
	for(int i=1;i<=n;i++){
		sum+=a[i].op;
		if(sum>(zifuchuan+1)/2){
			mark=i;
			//kl=sum-zifuchuan/2;
			//lk=a[i].z;
			break;
		}
	}
	
	int l=1,r=n;
	int sz=a[l].op,sz2=a[r].op;
	char ab=a[l].z,abc=a[r].z;
	while(l<=mark-1&&r>mark){
		if(ab!=abc){
			ans+=min(sz,sz2);
			if(sz!=sz2){
				if(sz>sz2){
					r--;
					sz=sz-sz2;
					sz2=a[r].op;
					abc=a[r].z;
				}else{
					l++;
					sz2=sz2-sz;
					sz=a[l].op;
					ab=a[l].z;
				}
			}else{
				l++;
				r--;
				sz2=a[r].op;
				abc=a[r].z;
				sz=a[l].op;
				ab=a[l].z;
				
			}
		}else{
			if(sz!=sz2){
				if(sz>sz2){
					r--;
					sz=sz-sz2;
					sz2=a[r].op;
					abc=a[r].z;
				}else{
					l++;
					sz2=sz2-sz;
					sz=a[l].op;
					ab=a[l].z;
				}
			}else{
				l++;
				r--;
				sz2=a[r].op;
				abc=a[r].z;
				sz=a[l].op;
				ab=a[l].z;
			}
		}
	}
	if(l==mark&&r!=mark){
		ab=a[l].z;
		sz=a[l].op;
		while(l<=r){
			if(ab!=abc){
				ans+=min(sz,sz2);
				if(sz!=sz2){
					if(sz>sz2){
						r--;
						sz=sz-sz2;
						sz2=a[r].op;
						abc=a[r].z;
					}else{
						l++;
						sz2=sz2-sz;
						sz=a[l].op;
						ab=a[l].z;
					}
				}else{
					l++;
					r--;
					sz2=a[r].op;
					abc=a[r].z;
					sz=a[l].op;
					ab=a[l].z;
				
				}
			}
			else{
				if(sz!=sz2){
					if(sz>sz2){
						r--;
						sz=sz-sz2;
						sz2=a[r].op;
						abc=a[r].z;
					}else{
						l++;
						sz2=sz2-sz;
						sz=a[l].op;
						ab=a[l].z;
					}
				}else{
						l++;
						r--;
						sz2=a[r].op;
						abc=a[r].z;
						sz=a[l].op;
						ab=a[l].z;
				}
			}
		}
	}else if(r==mark&&l!=mark){
		abc=a[r].z;
		sz2=a[r].op;
		while(l<=r){
			if(ab!=abc){
				ans+=min(sz,sz2);
				if(sz!=sz2){
					if(sz>sz2){
						r--;
						sz=sz-sz2;
						sz2=a[r].op;
						abc=a[r].z;
					}else{
						l++;
						sz2=sz2-sz;
						sz=a[l].op;
						ab=a[l].z;
					}
				}else{
					l++;
					r--;
					sz2=a[r].op;
					abc=a[r].z;
					sz=a[l].op;
					ab=a[l].z;
				}	
			}else{
				if(sz!=sz2){
					if(sz>sz2){
						r--;
						sz=sz-sz2;
						sz2=a[r].op;
						abc=a[r].z;
					}else{
						l++;
						sz2=sz2-sz;
						sz=a[l].op;
						ab=a[l].z;
					}
				}else{
						l++;
						r--;
						sz2=a[r].op;
						abc=a[r].z;
						sz=a[l].op;
						ab=a[l].z;
				}
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}//2e5*1e9=2e14;
