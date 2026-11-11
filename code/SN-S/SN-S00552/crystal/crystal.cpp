#include<bits/stdc++.h>
using namespace std;
vector<int>vs;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,a=0,s=0;
	cin>>n>>m;
	int csh=m;
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		vs.push_back(k);
	}
	sort(vs.begin(),vs.end());
	
	for(int i=0;i<n;i++){
		int t=vs[i];
		a=vs[i+1]-vs[i];
		if(csh<=0){
			if(t==vs[i+1]){
				s+=1;
				break;
			}
			break;
		}
		if(i<n&&vs[i]<vs[i+1]){
			for(int j=1;j<=i;j++){
				
				vs[j]+=a;
				csh-=a;
				s=i;
				if(csh<=0){
					break;
					s=i-1;
					cout<<s;
				}
			}
		}
	}
	cout<<s+1<<endl;
	return 0;
}
