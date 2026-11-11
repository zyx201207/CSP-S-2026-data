#include <bits/stdc++.h>
using namespace std;
int main(){
    //freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	int n;
	char b;
	string c;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i]>>b;
		for(int j=0;j<1;j++){
			c[i]=b;
		}
	}
	bool d[n]={0};
	string c2;
	for(int i=0;i<n;i++){
        for(int j=n;j>=0;j--){
            c2[i]=c[n];
        }
	}
    int ans=0;
	for(int i=0;i<n;i++){
        if(c[i]!=c2[i]){
            for(int i=0;i<n;i++){
                if(d[i]==0){
                    if(a[n-i]!=a[i]){
                        ans+=max(a[n-i],a[i])-min(a[n-i],a[i]);
                    }
                }else{
                    cout<<"0";
                    return 0;
                }
            }
        }
	}
	cout<<ans;
	return 0;
}

