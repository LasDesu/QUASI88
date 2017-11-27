#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED


/***********************************************************************
 * グラフィック処理 (システム依存)
 ************************************************************************/

extern	int	now_screen_size;	/* 現在の、画面サイズ		*/

extern	int	enable_fullscreen;	/* 全画面表示可能かどうか	*/
					/*    1:可 0:不可 -1:全画面のみ	*/
extern	int	now_fullscreen;		/* 現在、全画面表示中なら真	*/

extern	int	enable_half_interp;	/* HALF時、色補間可能かどうか	*/
extern	int	now_half_interp;	/* 現在、色補完中なら真		*/

extern	int	now_status;		/* 現在、ステータス表示中なら真	*/


typedef struct{
  unsigned	char	red;			/* Ｒ面輝度 0x00〜0xff	*/
  unsigned 	char	green;			/* Ｇ面輝度 0x00〜0xff	*/
  unsigned	char	blue;			/* Ｂ面輝度 0x00〜0xff	*/
  unsigned 	char	padding;
} SYSTEM_PALETTE_T;

void	setup_palette( SYSTEM_PALETTE_T syspal[] );





/***********************************************************************
 * グラフィックシステムの初期化・終了・再初期化
 *	graphic_system_init()    起動後に1度だけ呼ばれる。
 *				 成功時には、真を返す。
 *
 *	graphic_system_restart() 画面表示パラメータの変更毎に呼ばれる。
 *				 画面再描画の必要があれば、真を返す。
 *
 *	graphic_system_term()    終了時に呼ばれる。
 *
 *	グローバル変数 screen_size, use_fullscreen, show_status などを
 *	もとに、ウインドウを表示して、各種変数を設定する。
 ************************************************************************/
int	graphic_system_init( void );
void	graphic_system_term( void );
int	graphic_system_restart( void );


/***********************************************************************
 * 画面描画
 *	put_image_all()		全画面表示する。(ステータス部含む)
 *
 *	put_image()		(x0,y0)-(x1,y1) の矩形範囲を表示する。
 *				ただし、いずれかの値が負なら表示しない。
 *				st0 〜 st2 が真であれば、ステータス 0〜2 を
 *				表示する。
 ************************************************************************/

void	put_image_all( void );
void	put_image( int x0, int y0, int x1, int y1, int st0, int st1, int st2 );


/***********************************************************************
 * 色(パレット)の設定
 ************************************************************************/
void	trans_palette( SYSTEM_PALETTE_T syspal[] );


/***********************************************************************
 * ステータスを表示・非表示切り替え
 *	グローバル変数 show_status に基づいて切り替える
 *	状態不変なら 0 を、再描画不要なら 1 を、再描画必要なら 2 を返す
 ************************************************************************/
int	set_status_window( void );


/***********************************************************************
 * マウスのグラブ・表示を設定
 *	グローバル変数 grab_mouse 、 hide_mouse などに基づき、設定する。
 *	画面上にマウスカーソルが表示されているなら、真を返す。
 ************************************************************************/
int	set_mouse_state( void );


/***********************************************************************
 * HALFサイズ時の色補完の有効・無効を設定
 *	グローバル変数 use_half_interp の変更時に呼び出される。
 ************************************************************************/
int	set_half_interp( void );


/***********************************************************************
 * ウインドウのバーに表示するタイトルを設定
 ************************************************************************/
void	set_window_title( const char *title );


#endif	/* GRAPH_H_INCLUDED */