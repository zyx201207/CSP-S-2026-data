#include<fstream>
#include<vector>
std::ifstream fin("string.in");
std::ofstream fout("string.out");
int main(){
    long long n;
    fin>>n;
    long long out=0;
    std::vector<std::pair<char,long long>>a(n),d,e;
    for(long long i=0;i<n;i++){
        long long b;char c;
        fin>>b>>c;
        a[i]={c,b};
        out+=b;
    }
    long long s1=out/2;
    out/=2;
    long long sum1=0;
    for(long long i=0;i<n;i++){
        if(sum1+a[i].second>s1){
            if(s1-sum1==0){
                break;
            }
            d.push_back({a[i].first,s1-sum1});
            break;
        }
        d.push_back({a[i].first,a[i].second});
        sum1+=a[i].second;
    }
    sum1=0;
    for(long long i=n-1;i>=0;i--){
        if(sum1+a[i].second>s1){
            if(s1-sum1==0){
                break;
            }
            e.push_back({a[i].first,s1-sum1});
            break;
        }
        e.push_back({a[i].first,a[i].second});
        sum1+=a[i].second;
    }
    sum1=0;
    long long sum2=0;
    for(long long i=0,j=0;;){
        if((i==d.size())&&(j==e.size())){
            break;
        }
        if(sum2>sum1){
            long long c1=d[i].second;
            long long c2=sum2-sum1;
            if(d[i].first==e[j-1].first){
                out-=std::min(c2,c1);
            }
            sum1+=d[i].second;
            i++;

        }else if(sum1>sum2){
            long long c1=e[j].second;
            long long c2=sum1-sum2;
            if(d[i-1].first==e[j].first){
                out-=std::min(c2,c1);
            }
            sum2+=e[j].second;
            j++;
        }else{
            sum1+=d[i].second;
            i++;
        }
    }
    fout<<out;
}
