#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    int a[100005];
    for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	int maxn,nown=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i!=j){
				nown=a[i]&a[j];
				maxn=max(maxn,nown);
			}
		}
	}
	cout<<maxn;
    return 0;

}

