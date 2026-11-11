#include<bits/stdc++.h>
using namespace std;
vector <long long> a;
long long n,m,temp,i;
long long ans[500005];

bool flag;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>temp;
		a.push_back(temp);
	}
	for(int j=0;j<n;j++){
		vector <long long> q;
		for(int i=j;i<n;i++){
			flag=false;
			for(int k=0;k<q.size();k++){
				if(q[k]==a[i]&&flag!=true) flag=true;
				if(flag==true){
					q.erase(q.begin()+k);
					k--;
				}
			}
			q.push_back(a[i]);
		}
		for(int k=0;k<q.size();k++){
			ans[q[k]-1]++;
		}
	}
	i=0;
	while(m!=0){
		if(ans[i]!=0){
			cout<<ans[i++]<<" ";
			m--;	
		}
	}
	return 0;
}


