#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int a[N];
int n;
char c[N];
bool check(int mid){
	__int128 x=0;
	// 前后枚举 
	int l=1,r=n;
	int k=a[l];//2
	int kk=a[r];//1
	while(l<r){
		if(c[l]!=c[r]){
			if(k<kk){
				x+=(__int128)k;
				if(x>mid){
					return 0;
				}
				l++;
				kk-=k;
				k=a[l];
			}
			else if(k>kk){
				x+=(__int128)kk;
				if(x>mid){
					return 0;
				}
				r--;
				k-=kk;
				kk=a[r];
			}
			else{
				x+=(__int128)k;
				if(x>mid){
					return 0;
				}
				l++,r--;
				k=a[l];
				kk=a[r];
			}
		}
		else{
			if(k<kk){
				l++;
				kk-=k;
				k=a[l];
			}
			else if(k>kk){
				r--;
				k-=kk;
				kk=a[r];
			}
			else{
				l++,r--;
				k=a[l];
				kk=a[r];
			}
		}
	} 
	return 1;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	bool ok=1;
	char last;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		if(i==1){
			last=c[i];
		}
		else{
			if(last!=c[i]){
				ok=0;
			}
		}
	}
	if(ok){
		cout<<0;
		return 0;
	}
	int l=0,r=1e18;
	//假设已知最少 
	while(l<r){
		int mid=l+r>>1;
		if(check(mid)){
			r=mid;
		}
		else{
			l=mid+1;
		}
	}
	
	cout<<l;
	return 0;
}
