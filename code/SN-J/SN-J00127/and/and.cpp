#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> a;
int ans=-1;

int he(int x,int y){
	int num=0,cnt=0;
	while(max(x,y)){
		int x1=x%2,y1=y%2;
		if (x1==y1){
			for (int i=1;i<=cnt;i++){
				x1*=2; 
			}
			num+=x1;
		}
		else {
			num+=0;
		}
		cnt++;
		x/=2;
		y/=2;
	}
	return num;
}

int main(){
	freopen("and.in","r",stdin); 
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for (int i=0;i<n-1;i++){
		int x;
		cin>>x;
		a.push_back(x);
	}
	for (int i=0;i<n-1;i++){
		if (m==1){
			for (int j=0;j<n;j++){
				ans=max(a[i],ans);
			}
		}
		else if (m==n){
			ans=he(ans,a[i]);
		}
		else if (m==2){
			for (int j=i+1;j<n;j++){
				ans=max(he(a[j],a[i]),ans);
			}
		}
	}
	
	cout<<ans<<' ';
} 
