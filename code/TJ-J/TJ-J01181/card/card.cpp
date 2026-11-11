#include<bits/stdc++.h>
using namespace std;
int a[500005],b[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
for(int i=1;i<=n;i++){
	cin>>a[i];
}
    int n1=n;
    while(n--){
    	for(int i=n1-n;i<=n1;i++){
    		b[a[i]]++;
    		if(a[i]==a[i-1]&&i-1>=n1-n){
    			b[a[i]]--;
    			break;
			}
		}
	}
for(int i=1;i<=m;i++){
	cout<<b[i]<<" ";
}
	return 0;
}
