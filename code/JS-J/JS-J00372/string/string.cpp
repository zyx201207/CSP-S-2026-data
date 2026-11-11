#include<fstream>
std::ifstream fin("string.in");
std::ofstream fout("string.out");
const int maxn=200005;
long long a[maxn];
char c[maxn];
int main(){
    int n;
    fin>>n;
    std::string s;
    for(int i=1;i<=n;i++){
        fin>>a[i]>>c[i];
        for(int j=1;j<=a[i];j++)
            s+=c[i];
    }
    long long ans=0;
    for(long long i=1;i<=s.size()/2;i++)
        if(s[i-1]!=s[s.size()-i])
            ans++;
    fout<<ans<<'\n';
}
