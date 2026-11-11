#include <iostream>
#include <cstdio>
using namespace std;
int n,m,a[500001],b[300001];
struct card{
    int num;
    int time;
}pile[300001];
void seta(int time){
    for(int k = 1;k <= m;k++){
        if(pile[k].time >= time){
            pile[k].num = 0;
            pile[k].time = 0;
        }

    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++){
        seta(-1);
        for(int j = i;j <= n;j++){
            if(pile[a[j]].num){
                seta(pile[a[j]].time);

            }

            pile[a[j]].num = 1;
            pile[a[j]].time = j;

        }
        for(int j = 1;j <= m;j++){
            if(pile[j].num){
                b[j]++;
            }
        }
    }
    for(int j = 1;j <= m;j++){
        cout << b[j] << " ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
