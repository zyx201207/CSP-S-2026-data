#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,b,c,d,e,f,g,h,late,last;
    int a[10010];
    cin >> n;
    cin >> m;
    for(int i = 0;i < n;i++){
        cin >> b;
        a[i] = b;
        for(int j = 1;j < m;j++){
            a[j] = c;
            a[j+1] = d;
            a[j-1] = e;
            while(true){
                last = c % 2;
                late = c / 2;
                c = c - late;
                if(c / 2 == 0){
                    break;
                }
            }
            f = a[j-1] and a[j];
            g = a[j] and a[j + 1];
            h = a[j-1]and a[j+1];
            if(f > g){
                g = f;
            }
            else if(f < g){
                f = g;
            }
            else if(f > h){
                h = f;
            }
            else if(h < f){
                f = h;
            }
            else if(g > h){
                h = g;
            }
            else if(g < h){
                g = h;
            }
        }
        cout << h;
    }
    return 0;
    fclose(stdin);
    fclose(stdout);
}
