#include<bits/stdc++.h>
using namespace std;
bool cmap[30][30];
int use,h,z;
bool find =false;
struct step {
    char s[60];
    int len;
    step() {
        len=0;
    }
    void output() {
        for(int i=1; i<=len; i++)
            printf("%c",s[i]);
    }
    void put(int x,int y) {

        s[++len]=char(x+'A'-1);
        s[++len]=char(y+'0');
    }
    void lose() {
        len=len-2;
    }
};
step a;
void fs(int x,int y) {
    use++;
    cmap[x][y]=true;
    a.put(x,y);
    if(use==h*z) {

        a.output();
        abort();

    }
    if(x-2>0&&y-1>0&&cmap[x-2][y-1]==false)
        fs(x-2,y-1);
    if(x-2>0&&y+1<=z&&cmap[x-2][y+1]==false)
        fs(x-2,y+1);
    if(x-1>0&&y-2>0&&cmap[x-1][y-2]==false)
        fs(x-1,y-2);
    if(x-1>0&&y+2<=z&&cmap[x-1][y+2]==false)
        fs(x-1,y+2);
    if(x+1<=h&&y-2>0&&cmap[x+1][y-2]==false)
        fs(x+1,y-2);
    if(x+1<=h&&y+2<=z&&cmap[x+1][y+2]==false)
        fs(x+1,y+2);
    if(x+2<=h&&y-1>0&&cmap[x+2][y-1]==false)
        fs(x+2,y-1);
    if(x+2<=h&&y+1<=z&&cmap[x+2][y+1]==false)
        fs(x+2,y+1);
    use--;a.lose();cmap[x][y]=false;

    return;
}
int main() {
    memset(cmap,false,sizeof(cmap));

    use=0;
    scanf("%d %d",&z,&h);
    for(int i=1;i<=(h+1)/2;i++)
      for(int j=1;j<=(z+1)/2;j++)
        fs(i,j);
    printf("impossible");
    return 0;

}
