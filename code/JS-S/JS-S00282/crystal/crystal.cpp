#include<fstream>
#include<algorithm>
std::ifstream fin("crystal.in");
std::ofstream fout("crystal.out");
long long a[500005];
long long sum[500005];
int main(){
    long long N,M;
    fin>>N>>M;
    for(int i=1;i<=N;++i){
        fin>>a[i];
    }
    std::sort(a,a+N);
    for(int i=1;i<=N;++i){
        sum[i]=sum[i-1]+a[i];
    }
    int tail=1;
    int best=0;
    for(int head=1;head<=N;++head){
        while(tail<=N+1 and (a[tail-1]*(tail-head)-(sum[tail-1]-sum[head-1]))<=M){
            best=std::max(best,tail-head);
            tail++;
        }
    }
    fout<<best;
}
