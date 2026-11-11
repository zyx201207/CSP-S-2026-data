#include<iostream>
using namespace std;
int n,m,f[100000000],ans = 0,max1 = 0,a[50000],e[100000000];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long c,d = 0,aa = 0,jy,all = 0,fmin = 0,fz=0,maax = 0;
    cin >> n >> m;
    for(int i = 0;i<n;i++){
        cin >> c;
        a[i] = c;
    }
    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            jy = a[i] - a[j];
            if(jy >= 0){
                f[all] = jy;
            }
            else{
                f[all] = -1*jy;
            }
            all+=1;
        }
    }
    fmin = f[0];
    for(int i = 0;i<m;i++){
        for(int j = 0;j<all;j++){
            if(fz == 0){
                if(f[j] < fmin){
                    fmin = f[j];
                }
            }
            else{
                if(f[j]>e[i-1]&&f[j]<fmin){
                    fmin = f[j];
                }
            }
        }
        e[i] = fmin;
        fz = 1;
        fmin = 9999999999;
    }
    for(int i = 0;i<m;i++){
        maax += e[i];
        if(maax>=m){
            ans = i+1;
            break;
        }
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
