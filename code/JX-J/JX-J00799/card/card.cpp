#include<iostream>
#include<cstring>
using namespace std;
int n,m;
int a[500001];
int leave_i[300001];
int pm[1000001];
int have_k[300001];
int head,tail;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++)cin >> a[i];
    // cout << "no" << endl;
    for(int i=1;i<=n;i++){
        head = 500001;
        tail = head;
        memset(have_k,0,sizeof have_k);
        for(int j=i;j<=n;j++){
            if(have_k[a[j]]){
                have_k[a[j]] = 0;
                while(pm[tail] != a[j] && head < tail){
                    // cout << pm[head] << " " ;
                    tail--;
                    have_k[pm[tail]] = 0;
                }
                // cout << " &&11111" << endl;
                // head++;
                pm[tail++] = a[j];
                have_k[a[j]] = 1;
            }else{
                // cout << "tail:" << tail << " new:" << a[j] << endl;
                pm[tail++] = a[j];
                have_k[a[j]] = 1;
            }
            for(int f=head;f<tail;f++){
            // printf("head:%d,tail%d \n",head,tail);
            // cout << pm[f] << " ";
            // leave_i[pm[j]]++;
        }
            // printf("game:%d, card%d\n",i,j);
        }
        // for(int j=1;j<=1000001;j++)cout << 
        for(int j=head;j<tail;j++){
            // printf("head:%d,tail%d \n",head,tail);
            // cout << pm[j] << " ";
            leave_i[pm[j]]++;
        }
        // cout << endl;
    }
    for(int i=1;i<=m;i++)cout << leave_i[i] << " ";
}