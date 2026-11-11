#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
	int n,m;
	map<int,int> cnt;
    cin>>n>>m;
    vector<int> a(n);
    for(int& i:a){
        cin>>i;
    }
    for(int I=0;I<n;I++){
        queue<int> q;
        for(int i=I;i<n;i++){
            q.push(a[i]);
        }
        vector<int> d;
        while(!q.empty()){
            vector<int>::iterator it=find(d.begin(),d.end(),q.front());
            if(it!=d.end()){
                d.erase(it,d.end());
            }
            d.push_back(q.front());
            q.pop();
        }
        for(const int& i:d){
        	cnt[i]++;
		}
    }
    for(int i=1;i<=m;i++){
    	cout<<cnt[i]<<' ';
	}
	return 0;
}
