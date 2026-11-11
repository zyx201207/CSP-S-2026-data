#include <bits/stdc++.h>
using namespace std;
int c,t;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		signed long long n,d;
		cin>>n>>d;
		vector<long long> a;
		for(int i=1;i<=n;i++){
			int p;
			cin>>p;
			a.push_back(p);
		}
		int sum=0;
		for(int l=0;l<n-2;l++){	
			for(int r=l+3;r<n;r++){
				if(a[r]-a[l]<=d||a[r]-a[l]>2*d)
					break;
				int s=0;
				for(int i=l+1;i<r;i++){
					if(a[i]-a[l]<=d&&a[r]-a[i]<=d){
						s++;
					}	
					if(s>2)
						break;
				}
				if(s==2)
					sum++; 
			}
		}
		cout<<sum<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
