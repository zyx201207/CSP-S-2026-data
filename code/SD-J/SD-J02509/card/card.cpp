#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005],b[10000005];
vector <int> v,gunmu;
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	gunmu.push_back(-1);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	v.push_back(-1);
	for(int k=1; k<=n; k++) {
		for(int j=k; j<=n; j++) {
			bool flag=0;
			int i=0;
			int temp=a[j];
			for(int p=1; p<=v.size(); p++) {
				if(a[j]==v[p]) {
					flag=1;
					i=p;
					break; 
				}
			}
			if(flag) {
				vector <int> v1;
				v1.push_back(-1);
				for(int p=1;p<=i-1;p++){
					v1.push_back(v[p]);
				}
				v=v1;
			}
			v.push_back(temp);
		}
		
		for(int i=1; i<=v.size()-1; i++) {
			b[v[i]]++;
		}
		v=gunmu;
	}
	for(int i=1; i<=m; i++) {
		cout<<b[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
