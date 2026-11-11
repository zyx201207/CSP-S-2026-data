#include<bits/stdc++.h>
using namespace std;
const long long N = 5e5+10;
long long n,ans;
long long m,y;
long long a[N],an;
long long sum = 0,s;



int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.in","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=0; i<n;i++){
        cin>>a[i];
    }
    for(int i = n;i>0;i--){
		for(int j=0;j<i;j++){
			sum+= a[i]-a[j];
			if(sum>m){
				sum = 0;
				y++;
				continue;

			}
			if(y!=0){
                continue;
			}
			an = i;


		}

	}

    cout<<an;
    return 0;
}
