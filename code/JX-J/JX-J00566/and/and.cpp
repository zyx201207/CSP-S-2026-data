#include<bits/stdc++.h>
using namespace std;


int n,m;
long long num[200005];

int tw(int x){
    int res = 0;
    while(x>0){
        x = x>>1;
        res++;
    }
    return res;
}

int get_one(int x){
    int res = 0;
    while(x>0){
        res += (x & 1);
        x = x>>1;
    }
    return res;
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    //printf("%d",get_one(512));

    int maxn_v = -1;
    cin>>n>>m;
    //cout<< n << " " << m <<endl;
    for(int i = 0;i<n;i++){
        cin>>num[i];
        maxn_v = max(tw(num[i]),maxn_v);
    }
    int ind = -1;
    num[n] = ((1<<maxn_v) - 1);
    //cout << num[n] <<endl;
    for(int i = 1;i<=m;i++){
        int maxx = -1,ind = 1;
        for(int j = 0;j<n;j++){
            if(get_one(num[n] & num[j]) >= get_one(maxx)){
                ind = j;

                maxx = num[n] & num[j];
                //cout<<i<<endl;
                //printf("%d | %d | %d \n",num[ind],num[n],maxx);
            }
        }

        num[n] = maxx;
        num[ind] = 0;

    }

    cout<<num[n]<<endl;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
