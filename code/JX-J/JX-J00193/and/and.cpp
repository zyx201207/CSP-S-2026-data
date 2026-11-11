#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> arr(n,0);
	for(int i=0;i<n;i++){
        cin>>arr[i];
	}
	if(m==1){
        sort(a.begin(),a.end(),cmp);
        cout<<arr[0]<<endl;
	}
	else{
        if(m==2){
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    ans=max(ans,arr[i]^arr[j]);
                }
            }
            cout<<ans<<endl;
        }
        else{
            int temp=arr[0];
            for(int i=1;i<m;i++){
                temp^=arr[1];
            }
            cout<<temp<<endl;
        }

	}
	return 0;
}
