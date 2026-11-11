#include <bits/stdc++.h>
using namespace std;
long long islandy[5009]={},lens[5009]={};


int get_len(long long islandy[5009],int start,int ending,int d)
{
    int len=1,now=start;long long nower=islandy[now];

    while(true){
    while(islandy[now]<=nower+d) now++;
    now--;
    if(now>=ending) return len;
    else {nower=islandy[now];len++;}
    }

}



int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long c,t,n,d;int result=0;
    cin >> c >> t;

    for(int h=0;h<t;h++){
        cin >> n >> d;
        long long islandy[5009]={};lens[5009]={};result=0;
        for(int i=0;i<n;i++) cin >> islandy[i];
        sort(islandy,islandy+n);



        for(int i=0;i<n;i++){
            for(int j=1;j<n;j++) lens[j]=0;

            for(int j=i+1;j<n;j++){
                lens[get_len(islandy,i,j,d)]++;
            }

            for(int j=1;j<n;j++){
                if(lens[j]==2) result++;
            }

        }



        cout << result << endl;








    }


    return 0;
}
