#include <bits/stdc++.h>
using namespace std;
void lesson1(){
     int n,m;
     cin >> n >> m;
     vector<long long>a(n);
     for(int i = 0;i < n;i++){
        cin >> a[i];
     }
     sort(a.begin(),a.end());
     long long ans = 0;
     int mid = n/2;
     for(int j = 1;j<n;j++){
     	int count = a[j]-a[mid];
     	count += count;
     	if(count < m){
     		ans++;
		}
	 }
	 cout << ans+1 << endl;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    lesson1();
    return 0;
}
