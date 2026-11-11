#include<fstream>
std::ifstream fin("migrate.in");
std::ofstream fout("migrate.out");
long long x[2000006];
int fnext[2000006];
int pnext[2000006];
int main(){
    int C,T;
    fin>>C>>T;
    if(C==11 || C==12){
        while(T-->0){
            long long n,d;
            fin>>n>>d;
            for(int i=0;i<n;++i){
                fin>>x[i];
            }
            long long q=x[1]-x[0];
            if(d>=q*2){
                fout<<std::max(0LL,n-d/q-d/q+1)<<'\n';
            }else{
                fout<<0<<'\n';
            }
            for(int i=0;i<n;++i){
                x[i]=0;
            }
        }
    }else{
        while(T-->0){
            long long n,d;
            fin>>n>>d;
            for(int i=0;i<n;++i){
                fin>>x[i];
            }
            int tail=0;
            for(int i=0;i<n;++i){
                while(tail<n-1 && x[tail+1]-x[i]<=d){
                    tail++;
                }
                fnext[i]=tail;
            }
            int head=n-1;
            for(int i=n-1;i>=0;--i){
                while(head>=1 && x[i]-x[head-1]<=d){
                    head--;
                }
                pnext[i]=head;
            }
            long long ans=0;
            for(int i=0;i<n-1;++i){
                for(int j=i+1;j<n;++j){
                    int a[j-i+1];
                    int b[j-i+1];
                    int apos=i;
                    int anow=0;
                    bool flag=true;
                    while(fnext[apos]<j){
                        if(apos==fnext[apos]){
                            flag=false;
                            break;
                        }
                        apos=fnext[apos];
                        a[anow++]=apos;
                    }
                    if(!flag) continue;
                    int bpos=j;
                    int bnow=anow;
                    while(pnext[bpos]>i){
                        if(bpos==pnext[bpos]){
                            flag=false;
                            break;
                        }
                        bpos=pnext[bpos];
                        b[--bnow]=bpos;
                    }
                    if(!flag) continue;
                    int dif=0;
                    for(int k=0;k<anow;++k){
                        dif+=a[k]-b[k];
                    }
                    if(dif==1){
                        ans+=1;
                    }
                }
            }
            fout<<ans<<'\n';
            for(int i=0;i<n;++i){
                x[i]=0;
            }
        }
    }
}
