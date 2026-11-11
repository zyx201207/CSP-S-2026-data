#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	int n,m;
	cin>>n;
	cin>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int z1=a[n-1]/2+1;
	int z[z1]={0};
	for(int i=0;i<n;i++){
		if((a[i]/2)==1){
			z[a[i]/2+1]++;
		}
		else{
			z[a[i]/2]++;
		}
	}
	for(int j=0;j<z1;j++){
		cout<<z[j]<<" ";
	}
	cout<<endl;
	int max;
	int s;
	int big=0;
	for(int i=0;i<m;i++){
		max=0;
		for(int j=1;j<z1;j++){
			if(max<=z[j]){
				s=j;
				max=z[j];
			}
		}
		cout<<s<<endl;
		big+=s;
		z[s]=0;
	}
	cout<<big;
	return 0;
}

