#include<fstream>
std::ifstream fin("string.in");
std::ofstream fout("string.out");
int a[200005];
char c[200005];
long long sum=0;
int main()
{
    int n;
    fin>>n;
    for(int i=0;i<n;i++){
        fin>>a[i]>>c[i];
    }
    int i=0;
    int j=n-1;
    while(i<j){
        if(a[i]==a[j]){
            if(c[i]!=c[j]){
                sum+=a[i];
            }
            i++;
            j--;
        }
        else if(a[i]<a[j]){
            if(c[i]!=c[j]){
                sum+=a[i];
            }
            a[j]-=a[i];
            i++;
        }
        else{
            if(c[i]!=c[j]){
                sum+=a[j];
            }
            a[i]-=a[j];
            j--;
        }
    }
    fout<<sum;
}
