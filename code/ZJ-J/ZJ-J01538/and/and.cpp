#include <bits/stdc++.h>
using namespace std;
int a,b;
vector <int>n[30];
bool m[30][200010];
bool q[30];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>a>>b;
	for(int i=1; i<=a; i++){
		long long c;
		cin>>c;
		int d=1;
		while(c>0){
			int r=c%2;
			if(r==1){
				n[d].push_back(i);
			}
			c/=2;
			d++;
		}
	}
	int w=1,z=29;
	for(int i=29; i>=1; i--){
		if(n[i].size()<b){
			continue;
		}
		if(w==1){
			q[i]=1;
			w=0;
			z=i;
			for(int k=0; k<n[i].size(); k++){
				m[i][n[i][k]]=1;
			}
			continue;
		}
		int o=0;
		for(int k=0; k<n[i].size(); k++){
			if(m[z][n[i][k]])o++;
		}
		if(o<b)continue;
		q[i]=1;
		for(int k=0; k<n[i].size(); k++){
			if(m[z][n[i][k]]){
				m[i][n[i][k]]=1;
			}
		}
		z=i;
	}
	long long l=0;
	for(int i=29; i>=1; i--){
		l*=2;
		if(q[i])l++;
	}
	cout<<l;
}
