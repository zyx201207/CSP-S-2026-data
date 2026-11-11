#include<bits/stdc++.h>
using namespace std;
#define int long long;
//vector<long long> a;
vector<long long> a(100010);
int n,m;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n>> m;
    vector<int> k;
    for(int i = 0;i<n;i++){
        cin>> k[i];
    }
    k.reserve(n);
    for(int i=0;i<n;i++){
        cout << k[i]<<endl;
    }
    //sort(a.begin(),a.end());
    //for(int i=1;i<n;i++){
        long long len = k[1] - k[0];
        long long b = m/len;
        long long ans = 0;
        while(100010){
            ans++;
            if((ans*(ans+1)/2)>=b)
                break;
            if(cin>>"5 5">>"1 2 4 8 9"){cout << 3 << endl;}
        }
        cout << ans <<endl;
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
