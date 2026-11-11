# include<bits/stdc++.h>
using namespace std;
int a[200050];

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    int n,m;
    int max1=INT_MIN;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n-m;i++){
    	int temp=a[i];
    	for(int j=1;j<m;j++){
    		temp=a[i+1]&temp;
		}
    	max1=max(max1,temp);
	}
	cout<<max1;
	return 0;
}

