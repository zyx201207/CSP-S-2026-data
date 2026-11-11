#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+5;
int a[N],cha[N];
int n;
int Myfind(int x){
	int l=0,r=n-1,ans=-1,mid;
	while(l<r){
		mid=l+((r-l)>>1);
		if(a[mid]<=x){
			ans=mid;
			l=mid+1;
		}
		if(a[mid]>x){
			r=mid-1;
		}
	}
	return ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	unsigned long long m;
	cin>>n>>m;
	for(int i=0;i!=n;++i){
		cin>>a[i];
	}
	sort(a,a+n);
	int goal=n>>1;
	long long need=0;
	for(int i=0;i!=goal;++i){
		cha[i]=a[goal]-a[i];
		need+=cha[i];
	}
	int ans=Myfind(a[goal]);
	if(need==m){
		cout<<ans+1;
		return 0;
	}
	for(;ans<n;ans=Myfind(a[goal])){
		if(need<m){
			m-=need;
			need=0;
			goal=ans;
			int next=ans+1;
			int dis=a[next]-a[goal];
			if(m<ans*dis){
				cout<<ans;
				return 0;
			}else{
				need+=ans*dis;
				continue;
			}
		}else{
			cout<<ans;
			return 0;
		}
		
	}
	
	
	
} 
