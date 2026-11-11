#include<iostream>
using namespace std;
int n;
long long a[200001];
char c[200001];
long long ans=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i] >> c[i];
    }
    int rei;
    for(int i=1;i<=n/2;i++){
        rei = n - i + 1;
        if(rei == i)continue;
        if(a[rei] == a[i] && c[rei] == c[i])continue;
        if(a[rei] == a[i]){ans += a[rei];continue;}
        if(c[rei] == c[i]){
            if(a[rei] > a[i]){
                int cnt=a[i];
                int k=i;
                while(cnt < a[rei]){
                    k++;
                    if(c[k] != c[rei])ans += min(a[k],a[rei]-cnt);
                    cnt += a[k];
                }
            }else{
                int cnt=a[rei];
                int k=rei;
                while(cnt < a[i]){
                    k--;
                    if(c[k] != c[i])ans += min(a[k],a[i]-cnt);
                    cnt += a[k];
                }
            }
        }else{
            ans += min(a[rei],a[i]);
            if(a[rei] > a[i]){
                int cnt=a[i];
                int k=i;
                while(cnt < a[rei]){
                    k++;
                    if(c[k] != c[rei])ans += min(a[k],a[rei]-cnt);
                    cnt += a[k];
                }
            }else{
                int cnt=a[rei];
                int k=rei;
                while(cnt < a[i]){
                    k--;
                    if(c[k] != c[i])ans += min(a[k],a[i]-cnt);
                    cnt += a[k];
                }
            }
        }
    }
    cout << ans;
}