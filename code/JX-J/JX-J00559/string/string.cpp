#include<iostream>
#include<vector>
using namespace std;
struct t{
    int l;
    char c;
};
const int N = 1e5+5;
int n;
//t a[N];
vector<char>a;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int s;
        cin>>s;
        char c;
        cin>>c;
        for(int j=1;j<=s;j++){
            a.push_back(c);
        }
    }
    long long ans=0;
    for(int i=0,j=a.size()-1;i<j;i++,j--){
        if(a[i]!=a[j])ans++;
    }
    cout<<ans;
    return 0;
}
