#include<fstream>
#include<string>
int main(){
    std::ifstream fin("string.in");
    std::ofstream fout("string.out");
    int n;
    int a[200005];
    char s[n];
    fin>>n;
    for(int i=1;i<=n;i++){
        fin>>a[i]>>s[i];
    }
    std::string c;
    for(int i=1;i<=n;i++){
            int j=a[i];
        while(j>0){
            c+=s[i];
            j--;
        }
    }
    int sum=0;
    for(int i=1;i<=c.size()/2;i++){
        if(c[i]!=c[c.size()+1-i]){
            sum++;
        }
    }
    fout<<sum<<"\n";
}
