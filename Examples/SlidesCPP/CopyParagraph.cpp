#include <DOM/IParagraph.h>
#include <DOM/Paragraph.h>
#include <DOM/IParagraphCollection.h>
#include <DOM/IParagraphFormatEffectiveData.h>
#include <DOM/IParagraphFormat.h>
#include <DOM/BulletType.h>
#include <DOM/BulletFormat.h>
#include <DOM/BulletFormatEffectiveData.h>
#include <DOM/NumberedBulletStyle.h>
#include <DOM/IBulletFormat.h>
#include <DOM/IColorFormat.h>

#include "SlidesExamples.h"
using namespace Aspose;
using namespace Aspose::Slides;

using namespace System;

//ExStart:CopyParagraph 

Paragraph CopyParagraph(SharedPtr<IParagraph> par)
{
	SharedPtr<Paragraph> para = MakeObject<Paragraph>();

	// use CreateParagraphFormatData !!!
	SharedPtr<IParagraphFormatEffectiveData> paraData = par->CreateParagraphFormatEffective();

	// use ParagraphFormat  to set values

	para->get_ParagraphFormat()->set_Alignment(paraData->get_Alignment());
	para->get_ParagraphFormat()->set_DefaultTabSize(paraData->get_DefaultTabSize());
	para->get_ParagraphFormat()->set_MarginLeft(paraData->get_MarginLeft());
	para->get_ParagraphFormat()->set_MarginRight(paraData->get_MarginRight());
	para->get_ParagraphFormat()->set_FontAlignment(paraData->get_FontAlignment());
	para->get_ParagraphFormat()->set_Indent(paraData->get_Indent());
	para->get_ParagraphFormat()->set_Depth(paraData->get_Depth());
	para->get_ParagraphFormat()->set_SpaceAfter(paraData->get_SpaceAfter());
	para->get_ParagraphFormat()->set_SpaceBefore(paraData->get_SpaceBefore());
	para->get_ParagraphFormat()->set_SpaceWithin(paraData->get_SpaceWithin());


	para->get_ParagraphFormat()->get_Bullet()->set_Type(paraData->get_Bullet()->get_Type());
	para->get_ParagraphFormat()->get_Bullet()->set_Char(paraData->get_Bullet()->get_Char());
	para->get_ParagraphFormat()->get_Bullet()->get_Color()->set_Color(paraData->get_Bullet()->get_Color())  ;
	para->get_ParagraphFormat()->get_Bullet()->set_Height(paraData->get_Bullet()->get_Height()) ;
	para->get_ParagraphFormat()->get_Bullet()->set_Font(paraData->get_Bullet()->get_Font());
	para->get_ParagraphFormat()->get_Bullet()->set_NumberedBulletStyle(paraData->get_Bullet()->get_NumberedBulletStyle());
	para->get_ParagraphFormat()->set_FontAlignment(paraData->get_FontAlignment()) ;

	para->get_ParagraphFormat()->set_RightToLeft(paraData->get_RightToLeft() ? NullableBool::True : NullableBool::False);
	para->get_ParagraphFormat()->set_EastAsianLineBreak(paraData->get_EastAsianLineBreak() ? NullableBool::True : NullableBool::False);
	para->get_ParagraphFormat()->set_HangingPunctuation(paraData->get_HangingPunctuation() ? NullableBool::True : NullableBool::False);

	return para;
}
//ExEnd:CopyParagraph 