#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    long long n,m;
    cin>>n>>m;

    vector<long long> eng(n);

    for (int i=0;i<n;i++){
        cin>>eng[i];
    }

    sort(eng.begin(),eng.end());

    int ans=1;

    for(int i=0;i<n-1;i++){
    	if(eng[i]==eng[i+1])
    	ans++;
    	else
    	break;
	}

    for(int a=2;a<n;a++){
            if(eng[n-a+1]>=eng[n-2]){
            for(int i=0;i<m;i++){
                eng[n-a]=eng[n-a]+1;

                }
                ans=ans+1;
            }
            else
                break;
        }

    cout<<ans;
    return 0;
}

