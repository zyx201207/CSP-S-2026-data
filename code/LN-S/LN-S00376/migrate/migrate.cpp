#include <bits/stdc++.h>
using namespace std;
int c,t,n,d,zi,cnt,minn = 1e9+7;
vector<int> z[2000010],cha[2000010];
int cnt2;
void find(int a,int b,int num,int ch){
    if(a == b){
        int ori = minn;
        minn = min(minn,num);
        if(minn == ori){
            cnt++;
        }else if(minn<ori){
            cnt = 0;
            cnt++;
        }
        return;
    }
    for(int s = 0;s<b-a-1;s++){
        for(int l = 1;l<=d;l++){
            if(a == 0){
                if(d>=cha[ch][a+s]){
                    find(a+s+1,b,num++,ch);
                }
            }else{
                if(d>=cha[ch][a+s]-cha[ch][a-1]){
                    find(a+s+1,b,num++,ch);
                }
            }

        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    for(int i = 1;i<=t*2;i++){
        if(i%2 == 1){
            cin >> n >> d;
        }else{
            for(int j = 1;j<=n;j++){
                cin >> zi;
                z[i/2-1].push_back(zi);
                if(j>2){
                    cha[i/2-1].push_back(z[i/2-1][j-1]-z[i/2-1][j-2]+cha[i/2-1][j-3]);
                }else if(j == 2){
                    cha[i/2-1].push_back(z[i/2-1][j-1]-z[i/2-1][j-2]);
                }
            }
        }
    }
    for(int i = 0;i<t;i++){
        for(int j = 0;j<z[i].size();j++){
            for(int k = j+2;k<z[i].size();k++){
                find(j,k,0,i);
                if(cnt == 2){
                    cnt2++;
                }

            }
        }
        cout << cnt2;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
