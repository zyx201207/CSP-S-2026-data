#include <vector>
#include <bits/stdc++.h>
using namespace std;
struct shuijing{
    int energy;
};



int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;

    vector<shuijing> a{500005};
    vector<int> all_energy;
    for(int i=0;i<n;i++){
        cin>>a[i].energy;
        all_energy.push_back(a[i].energy);
    }


    sort(all_energy.begin(),all_energy.end(),greater<int>());
    int cnt = 0;
    int ans = 0;
    int cm = all_energy[0]-all_energy[1];
    for(int i=0;i<n;i++){
        int j=i+1;
        while(j<n){
            if(all_energy[i] - all_energy[j] >= cm){
                cnt++;
                cm = all_energy[i]-all_energy[j];
            }

            j++;
        }
        cm=m;
        if(ans<cnt){
            ans=cnt;
        }
        cnt=0;
    }
    cout<<ans;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
