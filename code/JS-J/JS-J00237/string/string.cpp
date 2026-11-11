#include<fstream>
using namespace std;
unsigned long long a[200005],ans=0;
char c[200005];
ifstream fin("string.in");
ofstream fout("string.out");
int main(){
    int n;
    fin>>n;
    string s="";
    for(int i=0;i<n;i++){
        fin>>a[i]>>c[i];
        for(int j=0;j<a[i];j++)
            s+=c[i];
    }
    for(int i=0;i<s.size()/2;i++){
        if(s[i]!=s[s.size()-1-i])ans++;
    }
    fout<<ans;
    return 0;
}
