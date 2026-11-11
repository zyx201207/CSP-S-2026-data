#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll s[100000005];
ll ch1[100000005];
ll he;

int a,b;
int m,n;
int ansm,ans;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    sort(s+0,s+n);
    for(int i=0;i<n-1;i++){
    	ch1[i]=s[i+1]-s[i];
	}
	for(int i=0;i<n;i++){
		int p=0;
		
		for(int j=i;j<n-1;j++){
			he=he+ch1[j]*(p+1);
			p++;
			if(he==m&&ch1[j+1]!=0){
				ans=j-i+2;
				if(ans>=ansm){
					ansm=ans;
				}
				break;
			}
			
			if(he>m){
				ans=j-i+1;
				if(ans>=ansm){
					ansm=ans;
				}
				break;
			}
			he=0;
		}
		
	}
	cout<<ansm;
 	
 	return 0;
	
}
