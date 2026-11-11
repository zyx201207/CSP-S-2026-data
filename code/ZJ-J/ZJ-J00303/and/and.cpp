#include<bits/stdc++.h>
using namespace std;
vector<int> aa[50],ab[50],c;
int n,m,b,sum,aum;
bool d[200005];
bitset<32> t;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>b;
		t=b;
		for(int j=31;j>=0;j--){
			if(t[j]){
				aa[j].push_back(b);
			}
		}
	}
	for(int i=31;i>=0;i--){
		if(aa[i].size()>=m){
			for(auto it:aa[i]){
				c.push_back(it);
			}
			break;
		}
	}
	sum=c.size();
	for(int i=0;i<c.size();i++){
		t=c[i];
		d[i]=true;
		for(int j=31;j>=0;j--){
			if(!t[j]){
				ab[j].push_back(i);
			}
		}
	}
	for(int i=31;i>=0;i--){
		if(c.size()-ab[i].size()>=m){
			for(auto it:ab[i]){
				if(d[it]){
					d[it]=false;
					sum--;
				}
			}
			if(sum==m){
				break;
			}
			else if(sum<m){
				aum=INT_MAX;
				int ma;
				for(int j=0;j<c.size();j++){
					if(d[j]){
						aum&=c[j];
					}
				}
				while(sum<m){
					ma=aum;
					for(int j=0;j<c.size();j++){
						if(!d[j]){
							if((aum&j)>ma){
								ma=(aum&j);
							}
						}
					}
					aum=ma;
					sum++;
				}
				cout<<aum;
				return 0;
			}
		}
	}
	aum=INT_MAX;
	for(int j=0;j<c.size();j++){
		if(d[j]){
			aum&=c[j];
		}
	}
	cout<<aum;
	return 0;
}
