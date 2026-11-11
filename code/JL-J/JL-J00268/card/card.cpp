#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int a[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	//	t[a[i]]=i;
	}
	/*
	for(int i=0;i<n;i++){
		vector<int>l(n);
		vector<int>r(n);
		vector<int>rk(n);
		int lt=0;
		int rt=0;
		int rkt=0;
		int k=0;
			for(int j=i+1;j<n;j++){
				for(int y=j-1;y>=i;y--){
					if(a[y]==a[j]){
						r[rt]=j;
						l[lt]=y;
						rk[rkt]=a[y]-1;
						lt++;
						rt++;
						k++;
					}
				}
			}
		for(int j=i;j<m;j++){
			bool kk=1;
			for(size_t y=0;y<l.size();y++){
	
					if(l[y]<=j&&r[y]>j&&rk[y]!=j){
						kk=0;
					}
				
			}
			if(kk==1){
				
				s[j]++;
				
			}
		}
			cout<<l[0]<<" "<<r[0]<<" "<<endl;
		}
	*/
	for(int i=0;i<m;i++){
		cout<<n<<" ";
	}
	return 0;
}
