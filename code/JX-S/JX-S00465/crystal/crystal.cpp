#include <bits/stdc++.h>
using namespace std;

int n,m;
long long T[600050];
long long Num = 0;
long long TT[600050];
long long Shu[600050];
long long Hou[600050];
long long HouShu[600050];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>T[i];
    }
    sort(T+1,T+1+n);
    int K = 0;
    for (int i=1;i<=n;i++){
        if (T[i-1]==T[i]){
            Shu[K]++;
        }else{
            K++;
            TT[K] = T[i];
            Shu[K] = 1;
        }
    }
    for (int i=1;i<=K;i++){
        HouShu[i] = HouShu[i-1] + Shu[i];
    }
    for (int i=1;i<=K;i++){
        Hou[i] = (TT[i]-TT[i-1])*HouShu[i-1] + Hou[i-1];
    }

    long long ansnum = 0;
    for (int i=1;i<=K;i++){
        long long nansnum = 0;
        long long l = 1,r = i,mid = 0;
        while (l<=r){
            mid = l + (r-l) / 2;
            if (Hou[i]-Hou[mid]-HouShu[mid]*(Shu[i]-Shu[mid])>m){
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        long long nanssum = HouShu[i]-HouShu[mid]+Shu[mid];
        if (nanssum>=ansnum) ansnum = nanssum;
    }
    cout<<ansnum;
    return 0;
}
