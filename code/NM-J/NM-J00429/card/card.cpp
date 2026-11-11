#include<bits/stdc++.h>
using namespace std;
int fi(vector<long long> &x,int i,int k) {
	for(int j=k; j<i; j++) {
		if(x[j]==x[i]) {
			return j;
		}
	}
	return -1;
}
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long m(0),n(0);
	scanf("%lld %lld",&m,&n);
	vector<long long> x(m),s(n+1);
	
	for(int i=0; i<m; i++) {
		cin>>x[i];
	}

	for(int k=0; k<m; k++) {
		vector<long long> t(m);
		for(int i=k; i<m; i++) {
			t[k]=x[k];
		}
		for(int i=0; i<t.size(); i++) {
					cout<<t[i]<<" ";
				}
				cout<<"\n";
		for(int i=k; i<m; i++) {
			int ind=fi(t,i,k);
			//cout<<ind<<" ";
			if(ind!=-1) {
				t.erase(t.begin()+ind,t.begin()+i);
				
			}
		}
		for(int i=1; i<=t.size(); i++) {
			s[t[i-1]]++;
		}
		
		
	}
	for(int i=1; i<=n; i++) {
		cout<<s[i]<<" ";
	}


	return 0;
}
