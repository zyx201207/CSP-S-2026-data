#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
int b[500010];
int c[500010];
int e[500010];
int ans;
long long sum;
bool full(int x){
	sum=0;
	for(int i=1;i<x;i++){
		sum+=a[x]-a[i];	
	}
	if(sum<m){
		return false;
	}else{
		return true ;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		
	}
	sort(a,a+n+1);
	int t=1;
	int tmp=a[t];
	int s=0;
	for(int i=1;i<=n;i++){//每项重复的个数 
		if(a[i]==tmp) {
			s++;
		}
		else{			
			for(int j=t;j<=t+s;j++){
				b[j]=s;
				c[j]=t;
				e[j]=t+s-1;

			}
			t+=s;
			tmp=a[t];
			s=1;		
		}
	}	
//	for(int i=1;i<=n;i++){
//		cout << b[i] << c[i] << e[i] << endl;
//		
//	}
	//二分找需合成数 
	int l=1;
	int r=n;
	int mid=(l+r)/2;
	while(l<r){
		
		ans=c[mid]+b[mid];

		
		if(full(mid)){
			r=mid-1;
			if(m-sum<e[mid]*(a[e[mid]+1]-a[e[mid]])){
				cout << ans;
				return 0;
			}
		} else{
			l=mid+1;
			if(sum==m){
				cout << ans;
				return 0;
			}
		}

		
		
	}
	return 0;
}

