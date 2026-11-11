#include<bits/stdc++.h>//jm99
#include<vector>//jm99
#define endl '\n'//jm99
#define ll long long //jm99
using namespace std;//jm99
ll n,m,a[500005],ans[300005];//jm99
int main(){//jm99
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);//jm99
	freopen("card.in","r",stdin);//jm99
	freopen("card.out","w",stdout);//jm99
    cin>>n>>m;//jm99
    for(int i=0;i<n;i++)cin>>a[i];//jm99
    for(int i=0;i<n;i++){//jm99
    	vector<int>v;//jm99
    	for(int j=i;j<n;j++){//jm99
    		v.push_back(a[j]);//jm99
    		for(int k=0;k<v.size()-1;k++){//jm99
    			if(v[j]==v[k]&&v[j]!=-1&&j!=k){//jm99
    				for(int l=k;l<j;l++)v[l]=-1;//jm99
				}//jm99
			}//jm99
		}//jm99
		for(int j=0;j<v.size();j++){//jm99
			if(v[j]!=-1)ans[v[j]]++;//jm99
			//cout<<v[j]<<" ";
		}//jm99
		//cout<<endl;
	}//jm99
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";//jm99
    return 0;//jm99
}//jm99
/*
我的最后一年OI生涯了，CCF多给我点分吧 
*/ 
